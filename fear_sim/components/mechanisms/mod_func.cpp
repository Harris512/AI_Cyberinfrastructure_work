#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern "C" void _gap_reg();
extern "C" void _k_rtm_reg();
extern "C" void _k_wb_reg();
extern "C" void _leak_reg();
extern "C" void _na_rtm_reg();
extern "C" void _na_wb_reg();
extern "C" void _vecevent_reg();

extern "C" void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," gap.mod");
fprintf(stderr," k_rtm.mod");
fprintf(stderr," k_wb.mod");
fprintf(stderr," leak.mod");
fprintf(stderr," na_rtm.mod");
fprintf(stderr," na_wb.mod");
fprintf(stderr," vecevent.mod");
fprintf(stderr, "\n");
    }
_gap_reg();
_k_rtm_reg();
_k_wb_reg();
_leak_reg();
_na_rtm_reg();
_na_wb_reg();
_vecevent_reg();
}
