SUBDIRS=$(wildcard */)
CLEANDIRS=$(SUBDIRS:%=clean-%)

all: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@

$(CLEANDIRS):
	@$(MAKE) -C $(@:clean-%=%) clean

.PHONY: clean $(CLEANDIRS) $(SUBDIRS)
clean: $(CLEANDIRS)
