# $Id: Makefile.am,v 1.15 2010/11/19 03:51:16 sarrazip Exp $

SUBDIRS = src

man_MANS = doc/burgerspace.6 doc/burgerspace-server.6

docdir = $(datadir)/doc/$(PACKAGE)-$(VERSION)
doc_DATA = \
	AUTHORS \
	COPYING \
	INSTALL \
	NEWS \
	README \
	THANKS \
	TODO

RPMBUILD = rpmbuild
rpm: dist
	$(RPMBUILD) -ta $(distdir).tar.gz

EXTRA_DIST = \
	bootstrap \
	autogen.sh \
	$(PACKAGE).spec \
	$(man_MANS) \
	macros/ac_compile_warnings.m4 \
	macros/getopt_long.m4 \
	$(PACKAGE).sln \
	$(PACKAGE).vcproj \
	$(PACKAGE)-core.vcproj \
	$(PACKAGE)-server.vcproj

ACLOCAL_AMFLAGS = -I macros

MAINTAINERCLEANFILES = \
	Makefile.in \
	aclocal.m4 \
	configure \
	config.guess \
	config.sub \
	depcomp \
	install-sh \
	missing \
	mkinstalldirs

