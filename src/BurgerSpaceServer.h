/*  $Id: BurgerSpaceServer.h,v 1.6 2013/02/25 05:04:43 sarrazip Exp $
    BurgerSpaceServer.h - Main engine

    burgerspace - A hamburger-smashing video game.
    Copyright (C) 2001-2013 Pierre Sarrazin <http://sarrazip.com/>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301, USA.
*/

#ifndef _H_BurgerSpaceServer
#define _H_BurgerSpaceServer

#include "IngredientGroup.h"
#include "IngredientSprite.h"
#include "Controller.h"

#include <flatzebra/GameEngine.h>
#include <flatzebra/Sprite.h>
#include <flatzebra/SoundMixer.h>
#include <flatzebra/KeyState.h>

#include <string>
#include <iostream>


class BurgerSpaceServerInterface
{
public:

    virtual ~BurgerSpaceServerInterface() {}

    virtual void startNewGame() = 0;

    virtual bool isPaused() const = 0;

    virtual void pauseGame() = 0;

    virtual void resumeGame() = 0;

    virtual void setChefRequest(const bool desiredDirections[4], bool shootPepper) = 0;

    virtual void setEnemyRequest(const bool desiredDirections[4]) = 0;

    // Returns true if the game must continue, or false to have it stop.
    virtual bool update() = 0;

    virtual void disconnect() = 0;

    // Must return true for success, or false for failure.
    virtual bool saveGame(std::ostream &out) = 0;

    // Must return 0 for success, or a negative error code for failure.
    virtual int loadGame(std::istream &in) = 0;

};


class BurgerSpaceServer : public BurgerSpaceServerInterface
{
public:

    BurgerSpaceServer(int initLevelNumber, bool _oldMotionMode) throw(int, std::string);

    void finishInit();  // must be called after constructor -- calls virtual functions

    virtual ~BurgerSpaceServer();

    // Returns true if the game must continue, or false to have it stop.
    virtual bool update();

    enum SpriteType
    {
        NO_SPRITE,
        CHEF,
        PEPPER,
        EGG,
        HOTDOG,
        PICKLE,
        TOP_BUN,
        LETTUCE,
        MEAT,
        RED_STUFF,
        YELLOW_STUFF,
        BOTTOM_BUN,
        TREAT,
        DIGIT,
    };

    enum SoundEffect
    {
        ingredientBouncesSound,
        ingredientInPlateSound,
        ingredientFallsSound,
        ingredientLoweredSound,
        enemyCatchesChefSound,
        enemyParalyzedSound,
        enemySmashedSound,
        chefThrowsPepperSound,
        chefGetsTreatSound,
        chefShootsBlanksSound,
        newGameStartsSound,
        levelFinishedSound,
        treatAppearsSound,
        treatDisappearsSound,
    };

    virtual void updateLevel(int levelNo, size_t numRows, size_t numColumns,
                             flatzebra::Couple levelPos, const std::string &desc) = 0;

    // Calls virtual method updateLevel() with parameters
    // taken from the current level.
    void sendLevelUpdate();

    // Calls virtual method updateScore() with parameters
    // taken from the current game state, and passed true
    // for 'forceTransmission'.
    void sendScoreUpdate();

    // pixmapIndex is allowed to be size_t(-1) to indicate that the sprite
    // must not be displayed.
    virtual void updateSprite(uint32_t id, SpriteType type, flatzebra::Couple pos, size_t pixmapIndex) = 0;

    virtual void notifySpriteDeletion(uint32_t id) = 0;

    virtual void updateScore(long theScore, int numLives, int numAvailablePeppers,
                             int cumulLevelNo, bool forceTransmission) = 0;

    virtual void playSoundEffect(SoundEffect se) = 0;

    virtual EnemyType chooseEnemyType();

    virtual bool isUserControlledEnemy(const flatzebra::Sprite &s) const;

    // Inherited from BurgerSpaceServerInterface:
    virtual void startNewGame();
    virtual bool isPaused() const;
    virtual void pauseGame();
    virtual void resumeGame();
    virtual void setChefRequest(const bool desiredDirections[4], bool shootPepper);
    virtual void setEnemyRequest(const bool desiredDirections[4]);

private:

    ///////////////////////////////////////////////////////////////////////////
    //
    //  LOCAL TYPES, CLASSES AND CONSTANTS
    //
    //

    struct IntPair
    {
        int first, second;
    };


    struct IntQuad
    {
        int first, second, third, fourth;
    };


public:

    class Level
    {
    public:
        Level();
        ~Level();

        void init(int no, int nCols, int nRows, flatzebra::Couple posInPixels);
        void setLevelNo(int no);
        int  getLevelNo() const;
        void setTileMatrixEntry(int colNo, int rowNo,
                                const char **xpm, SDL_Surface *pixmap);
        SDL_Surface **getTileMatrixRow(int rowNo);
        const char **getXPMAtPixel(flatzebra::Couple pos) const;

        void setTextDescription(const std::string &desc);
        std::string getTextDescription() const;

    public:
        flatzebra::Couple sizeInTiles;
        flatzebra::Couple sizeInPixels;
        flatzebra::Couple positionInPixels;

    private:
        int levelNo;
        const char ***xpmMatrix;   // array of 'const char **' pointers
        SDL_Surface **tileMatrix;  // array of X11 pixmaps
        std::string desc;  // see BurgerSpaceServer::loadLevel()

        // Forbidden operations:
        Level(const Level &);
        Level &operator = (const Level &);
    };

protected:

    class IngInit
    {
    public:
        enum IngType
        {
            BOTTOM_BUN, MEAT, LETTUCE, RED_STUFF, YELLOW_STUFF, TOP_BUN

            /*        The red stuff is a slice of tomato, and the yellow stuff
                is cheese.  This was not known at the time when this
                enumeration was defined...
            */
        };

        int xInitTile, yInitTile, yTargetTile, rank;
        IngType type;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    //  DATA MEMBERS
    //
    //

    static const char
        *levelDescriptor1[],
        *levelDescriptor2[],
        *levelDescriptor3[],
        *levelDescriptor4[],
        *levelDescriptor5[],
        *levelDescriptor6[];

    static const char **levelDescriptorTable[];

    static const IngInit
        tableIngredientsLevel1[],
        tableIngredientsLevel2[],
        tableIngredientsLevel3[],
        tableIngredientsLevel4[],
        tableIngredientsLevel5[],
        tableIngredientsLevel6[];

    static const IngInit *tableOfTablesOfIngredientsLevel[];

    static const IntQuad enemyStartingHeights[];
    static const IntPair playerStartingPos[];


    flatzebra::Couple theScreenSizeInPixels;

    int initLevelNo;  // level number at which play starts
    int cumulLevelNo;

    enum RequestType { NO_REQUEST, START_GAME_REQUEST, PAUSE_REQUEST, RESUME_REQUEST };

    RequestType currentRequest;
    bool paused;
    unsigned long tickCount;


    /*  PLAYER:
    */
    flatzebra::Couple initPlayerPos;  // initial player position in a level
    flatzebra::PixmapArray playerPA;
    flatzebra::Sprite *playerSprite;
    int lastPlayerDirection;
    bool oldMotionMode;
    bool desiredDirs[4];
    bool chefWantsToShootPepper;

    flatzebra::PixmapArray pepperPA;
    flatzebra::SpriteList  pepperSprites;

    /*  ENEMIES:
    */
    unsigned long timeForNewEnemy;
                // tick count at which a new enemy must be created;
                // 0 means none

    flatzebra::PixmapArray eggPA;
    flatzebra::PixmapArray hotdogPA;
    flatzebra::PixmapArray picklePA;
    flatzebra::SpriteList  enemySprites;
    unsigned enemyTypeCounter;  // used to generate new enemy sprites
    int requestedEnemyDirection;  // RIGHT, UP, LEFT, DOWN, or -1 for none


    /*  INGREDIENTS:
    */
    flatzebra::PixmapArray topBunPA;
    flatzebra::PixmapArray lettucePA;
    flatzebra::PixmapArray meatPA;
    flatzebra::PixmapArray redStuffPA;
    flatzebra::PixmapArray yellowStuffPA;
    flatzebra::PixmapArray bottomBunPA;
    IngredientSprite::List ingredientSprites;  // owns the contained objects
    IngredientGroup::List  ingredientGroups;
                                    // contained objects must come from 'new'


    /*  TREATS (icecream, etc, that the player eats to get a pepper):
    */
    flatzebra::PixmapArray treatPA;
    flatzebra::SpriteList treatSprites;
    int timeForTreat;


    /*  DIGITS:
    */
    flatzebra::PixmapArray digitPA;
    flatzebra::SpriteList scoreSprites;


    int    numHamburgersToDo;
    long   thePeakScore;  // player's best score yet in this game

    long   theScore;      // player's score in points

    bool   celebrationMode;  // used when player has just won the level

    int    numLives;  // number of player lives left

    int    numAvailablePeppers;  // number of pepper shots available to player

    int cooldowntime; //time of the cooldown

    int cooldown; //cooldown

    int maxAvailablePeppers; // maximum peppers the player can have

    Level theCurrentLevel;


    ///////////////////////////////////////////////////////////////////////////
    //
    //  IMPLEMENTATION FUNCTIONS
    //
    //
    void chooseDirectionAmongMany(bool directions[4]) const;
    int  chooseDirectionTowardTarget(
                            flatzebra::Couple startPos, flatzebra::Couple targetPos, int speedFactor,
                            const bool allowedDirections[4]) const;
    void getPlayerDesiredDirections(bool desiredDirs[4]) const;

    bool animatePlayer();
    void animateAutomaticCharacters();
    void detectCollisions();
    void drawSprites();

    void putSprite(const flatzebra::Sprite &s);
    void showInstructions();
    void initGameParameters();
    void initNextLevel(int levelNo = 0) throw(int);
    void resetPlay();
    int isPositionAtSideOfStructure(flatzebra::Couple pos) const;
    void animateTemporarySprites(flatzebra::SpriteList &slist) const;
    void givePlayerPepper();
    void dispenseBurger();
    void makePlayerWin();
    void makePlayerDie();
    void releaseAllCarriedEnemies();
    void detectEnemyCollisions(flatzebra::SpriteList &slist);
    void detectCollisionBetweenIngredientGroupAndEnemyList(
            const IngredientGroup &aGroup, flatzebra::SpriteList &enemies);
    bool ingredientGroupCollidesWithSprite(
                        const flatzebra::Couple groupPos, const flatzebra::Couple groupSize,
                        const flatzebra::Sprite &s) const;
    void loadLevel(int levelNo) throw(std::string);
    void displayErrorMessage(const std::string &msg) throw();
    void createPlayerSprite();
    void initializeSprites() throw(flatzebra::PixmapLoadError);
    void initializeMisc() throw(std::string);
    void deleteSprite(flatzebra::Sprite *s) const;
    void deleteSprites(flatzebra::SpriteList &sl) const;
    void deleteSprites(IngredientSprite::List &isl) const;
    IngredientGroup *findIngredientGroupRightBelow(
                                        const IngredientGroup &upperGroup);
    bool isIngredientSpriteOnFloor(const IngredientSprite &s) const;
    bool spriteTouchesIngredientGroup(
                            const flatzebra::Sprite &s, const IngredientGroup &g) const;
    size_t carryEnemies(IngredientGroup &g);
    size_t carryEnemiesInList(IngredientGroup &g, flatzebra::SpriteList &slist);
    size_t releaseCarriedEnemies(IngredientGroup &g);
    void createScoreSprites(long n, flatzebra::Couple center);
    void loadPixmaps() throw(flatzebra::PixmapLoadError);
    void moveEnemyList(flatzebra::SpriteList &slist, int speedFactor);
    flatzebra::Couple getDistanceToPerfectPos(const flatzebra::Sprite &s) const;
    bool isSpriteOnFloor(const flatzebra::Sprite &s) const;
    flatzebra::Couple determineAllowedDirections(const flatzebra::Sprite &s,
                                    int speedFactor, int tolerance,
                                    bool allowedDirections[4]) const;
    flatzebra::Couple attemptMove(const flatzebra::Sprite &s, bool attemptLeft, bool attemptRight,
                        bool attemptUp, bool attemptDown,
                        int speedFactor) const;
    bool positionAllowsLeftMovement(flatzebra::Couple pos, flatzebra::Couple size) const;
    bool positionAllowsRightMovement(flatzebra::Couple pos, flatzebra::Couple size) const;
    bool spriteBottomCenterIsOnLadder(const flatzebra::Sprite &s) const;
    bool spriteBottomCenterIsOverLadder(const flatzebra::Sprite &s) const;
    void drawComplexEnemySprites(const flatzebra::SpriteList &slist, int oscBit);
    void addToScore(long n);
    void addToNumLives(int n);
    void initTimeForTreat();
    void changePauseState(bool newPauseState);
    void displayStartMessage(bool display);

    void drawQuitDialog();
    bool doQuitDialog();

    void drawSaveDialog();
    void drawLoadDialog();
    int  getSlotNumber();
    void doSaveDialog();
    void doLoadDialog();
    void showDialogBox(const std::string &msg);

    std::string serialize(flatzebra::Couple c) const;
    std::string serialize(const flatzebra::Sprite &s) const;
    std::string serialize(const EnemySprite &s) const;
    int encodePixmapArrayPointer(const flatzebra::PixmapArray *ptr) const;
    const flatzebra::PixmapArray *decodePixmapArrayCode(int) const;
    void serializeSpriteList(std::ostream &out,
                                    const flatzebra::SpriteList &list) const;
    void serializeEnemySpriteList(std::ostream &out,
                                    const flatzebra::SpriteList &list) const;
    std::string serialize(const IngredientSprite &is) const;
    bool deserialize(std::istream &in, flatzebra::Couple &c) const;
    flatzebra::Sprite *deserializeSprite(std::istream &in,
                                        bool enemy = false) const;
    bool deserializeSpriteList(std::istream &in,
                                flatzebra::SpriteList &list,
                                bool enemies = false) const;
    IngredientSprite *deserializeIngredientSprite(std::istream &in,
                                                IngredientGroup *ig) const;
    static std::string getSavedGamesDir();
    static std::string formSavedGameFilename(int slotNum);
    void showSlotDirectory();


    /*        Forbidden operations:
    */
    BurgerSpaceServer(const BurgerSpaceServer &);
    BurgerSpaceServer &operator = (const BurgerSpaceServer &);
};


#endif  /* _H_BurgerSpaceServer */
