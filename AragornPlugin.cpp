#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "AragornPlugin.h"

void AragornPlugin::input(std::string file) {
 inputfile = file;
}

void AragornPlugin::run() {
   
}

void AragornPlugin::output(std::string file) {
 // spades.py -o 02_Aragorn -1 $1 -2 $2 --careful
 // assembly-stats -t ./All_assemblies/*.fasta > ./All_assemblies/00_Metrics_all_assemblies.txt
 // qualimap bamqc -bam assembly_map_long-reads.bam -outfile Qualimap_map_long.pdf
	std::string command = "aragorn "+inputfile+" >& "+file;
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<AragornPlugin> AragornPluginProxy = PluginProxy<AragornPlugin>("Aragorn", PluginManager::getInstance());
