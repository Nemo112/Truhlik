
difference(){
    cube([63,19,10]);
    translate([16,5.5,2])cube([12,8,8]);
    translate([49,5.5,7])cube([14,8,4]);
    translate([16+14,5.5,2+4])cube([18,8,4]);
}

translate([0,-2,0])cube([63,2,33]);
translate([0,19,0])cube([63,2,33]);

difference(){
    translate([63,-2,0])cube([2,23,33]);
    translate([63,5.5,7])cube([2,8,5]);
}