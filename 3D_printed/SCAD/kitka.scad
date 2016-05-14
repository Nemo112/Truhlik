
translate([106/2,106/2,100/2+3]){
    translate([0,0,-100/2-3/2])cube([106,106,3],center=true);
    difference(){
        cube([106,106,100],center=true);
        cube([100,100,100],center=true);
        translate([106/2-3,100/2-10,94/2])rotate([0,90,0])cylinder(r=4, h=3);
    }
}

translate([96,0,0])cube([80, 3, 103]);
translate([96,103,0])cube([80, 3, 103]);
translate([96,0,0])cube([80, 106, 3]);

translate([96+80,0,0])cube([3, 106, 103]);


translate([60,-18-2,70]){
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
}

translate([106,7,93]){
    difference(){
        cube([40,40,2]);
        translate([20,8,0])cylinder(d=10,h=2);
        translate([5,8,0])cylinder(d=1.5,h=2);
        translate([35,4,0])cylinder(d=1.5,h=2);
    }
    translate([0,-4,0])cube([40,4,2]);
    translate([40,-4,0])cube([1,44,10]);
    translate([0,40-1,0])cube([40,1,10]);
}