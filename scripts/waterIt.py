#!/usr/bin/python
import urllib2

out = urllib2.urlopen("http://10.0.0.174:9010/water").read()
print out
