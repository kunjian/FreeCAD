# IntFeatPair gui init module
# (c) 2001 Juergen Riegel LGPL

class IntFeatPairWorkbench ( Workbench ):
	"IntFeatPair workbench object"
	MenuText = "IntFeatPair"
	ToolTip = "IntFeatPair workbench"
	def Initialize(self):
		# load the module
		import IntFeatPairGui
	def GetClassName(self):
		return "IntFeatPairGui::Workbench"

Gui.addWorkbench(IntFeatPairWorkbench())
