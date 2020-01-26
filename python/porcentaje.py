#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 16:09:34 2019

@author: fernando
"""
#funcion con el calculo
def calculo(c1,p1,c2):
    base = c1/p1
    p2 = (c2/base)
    print ("Si "  + str(c1) + " es el " + str(p1) + "%, entonces " + str(c2) + " es el " + str(p2) + "%")
  
#programa principal
c1 = input("Cantidad inicial ")
p1 = input("% de la cantidad ")
c2 = input("cantidad de la que quiero saber el % ")
calculo(float(c1),float(p1),float(c2))