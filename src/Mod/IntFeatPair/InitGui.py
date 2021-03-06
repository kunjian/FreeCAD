# IntFeatPair gui init module
# (c) 2001 Juergen Riegel LGPL

class IntFeatPairWorkbench(Workbench):
    "IntFeatPair workbench object"

    def __init__(self):
        self.__class__.Icon = FreeCAD.getResourceDir() + "Mod/IntFeatPair/Resources/icons/AssemblyWorkbench.svg"
        self.__class__.MenuText = "IntFeatPair"
        self.__class__.ToolTip = "Interaction feature pair workbench"

    def Initialize(self):
        # load the module
        import IntFeatPairGui
        import IntFeatPair

    def GetClassName(self):
        return "IntFeatPairGui::Workbench"

Gui.addWorkbench(IntFeatPairWorkbench())
