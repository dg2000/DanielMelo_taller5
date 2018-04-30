import numpy as np

import matplotlib.pyplot as plt

import os


datos = np.loadtxt("datos.txt")

hola = np.loadtxt("datos.txt")[0, :]

x = np.loadtxt("datos.txt")[:, 0]

original = np.loadtxt("datos.txt")[:, 1]

imagenes = np.array([])

alf = map(chr, range(97, 123)) 


for i in range(1, len(hola)):
    y = datos[:, i]
    plt.figure()
    plt.plot(x, y)
    plt.ylim(-1.0, 1.0)
    if(i >= 9.0*len(alf)):
        plt.savefig(str(alf[9]) + str(alf[i-9*len(alf)])  + '.png')
    elif(i >= 8.0*len(alf)):
        plt.savefig(str(alf[8]) + str(alf[i-8*len(alf)])  + '.png')
    elif(i >= 7.0*len(alf)):
        plt.savefig(str(alf[7]) + str(alf[i-7*len(alf)])  + '.png')
    elif(i >= 6.0*len(alf)):
        plt.savefig(str(alf[6]) + str(alf[i-6*len(alf)])  + '.png')
    elif(i >= 5.0*len(alf)):
        plt.savefig(str(alf[5]) + str(alf[i-5*len(alf)])  + '.png')
    elif(i >= 4.0*len(alf)):
        plt.savefig(str(alf[4]) + str(alf[i-4*len(alf)])  + '.png')
    elif(i >= 3.0*len(alf)):
        plt.savefig(str(alf[3]) + str(alf[i-3*len(alf)])  + '.png')
    elif(i >= 2.0*len(alf)):
        plt.savefig(str(alf[2]) + str(alf[i-2*len(alf)])  + '.png')
    elif(i >= len(alf)):

        plt.savefig(str(alf[1]) + str(alf[i-len(alf)]) +  '.png')
    else:
        plt.savefig(str(alf[0]) + str(alf[i]) +  '.png')
            
    plt.close()



os.system('convert *.png cuerda.gif')
