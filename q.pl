#!/usr/bin/perl -w

while(<>){
	if (not (
		  /^[^2]*13/ || /^[^2]*31/ ||
		  /^[^4]*17/ || /^[^4]*71/ ||
		  /^[^6]*39/ || /^[^6]*93/ ||
		  /^[^8]*79/ || /^[^8]*97/ ||
		  /^[^5]*19/ || /^[^5]*91/ ||
		  /^[^5]*37/ || /^[^5]*73/ ||
		  /^[^5]*28/ || /^[^5]*82/ ||
		  /^[^5]*46/ || /^[^5]*64/ 
		)
	){ print;}
}
