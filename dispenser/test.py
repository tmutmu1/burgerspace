import dispense
try:
  import config
except ImportError:
    print ("no config.py found.  Please copy sample_config.py to config.py.")


dispense.dispense_init()
dispense.dispense_back(config.servo_channel)
time.sleep(2)
dispense.dispense_forward(config.servo_channel)


