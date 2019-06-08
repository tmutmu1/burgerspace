Name:           burgerspace
Version:        1.9.2
Release:        1%{?dist}
Summary:        A hamburger-smashing video game
Summary(fr):    Un jeu de hamburgers qu'on écrase

Group:          Amusements/Games
License:        GPLv2+
URL:            http://sarrazip.com/dev/%{name}.html
Source0:        http://sarrazip.com/dev/%{name}-%{version}.tar.gz
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires:  flatzebra-devel >= 0.1.6
BuildRequires:  desktop-file-utils

%description
BurgerSpace is a game in which you are a chef who must walk
over hamburger parts (buns, meat, lettuce, etc) to make them fall from
floor to floor, until they end up on the plates at the bottom of the
screen.  It is a clone of the 1982 BurgerTime video game by Data East.

%description -l fr
BurgerSpace est un jeu où vous êtes un chef qui doit marcher
sur des tranches de hamburger (pain, viande, laitue, etc) pour
les faire tomber d'étage en étage, jusqu'à ce qu'ils se retrouvent
dans les assiettes au bas de l'écran.  Il s'agit d'un clone du jeu
BurgerTime créé par Data East en 1982.

%prep
%setup -q


%build
%configure
make %{?_smp_mflags}


%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT
desktop-file-validate $RPM_BUILD_ROOT/%{_datadir}/applications/%{name}.desktop


%clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(-,root,root,-)
%{_bindir}/%{name}
%{_bindir}/%{name}-server
%{_datadir}/pixmaps/%{name}.png
%{_datadir}/sounds/%{name}
%{_datadir}/applications/%{name}.desktop
%{_mandir}/man6/%{name}.6.gz
%{_mandir}/man6/%{name}-server.6.gz
%doc %{_defaultdocdir}/*


%changelog
