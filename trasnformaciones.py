def multiplicarMatrices(matriz, matriz2):

    multiplicacion = [[0] * 2 for i in range(len(matriz))]
    for i in range(len(multiplicacion)):
        for j in range(len(multiplicacion[i])):
            for k in range(len(matriz2)):
                    multiplicacion [i][j]=multiplicacion[i][j]+matriz[i][k]*matriz2[k][j]
    print(multiplicacion)
    return multiplicacion
def scale2(a,axis):
    if(axis=="X" or axis=="x"):
        return np.matrix([[a,0],
                         [0,1]])
    elif(axis=="Y" or axis=="y"):
        return np.matrix([[1,0],
                         [0,a]])
def reflexion(eje):
    if(eje=="Y" or eje=="y"):
        transformacion = [[0] * 2 for i in range(2)]
        transformacion[0][0]=-1
        transformacion[0][1]=0
        transformacion[1][0]=0
        transformacion[1][1]=1
        #print(transformacion)
        return transformacion
        #print(matriz)
    elif(eje=="X" or eje=="x"):
        transformacion = [[0] * 2 for i in range(2)]
        transformacion[0][0]=1
        transformacion[0][1]=0
        transformacion[1][0]=0
        transformacion[1][1]=-1
        #print(transformacion)
    return transformacion
def rotar(c):
    
    transformacion = [[0] * 2 for i in range(2)]
    transformacion[0][0]=math.cos(math.radians(c))
    transformacion[0][1]=math.sin(math.radians(c))
    transformacion[1][0]=math.sin(math.radians(c))*(-1)
    transformacion[1][1]=math.cos(math.radians(c))
    print(transformacion)
    return transformacion
def corte(eje,a):
    if(eje=="Y" or eje=="y"):
        transformacion = [[0] * 2 for i in range(2)]
        transformacion[0][0]=1
        transformacion[0][1]=0
        transformacion[1][0]=a
        transformacion[1][1]=1
        #print(transformacion)
        return transformacion
        #print(matriz)
    elif(eje=="X" or eje=="x"):
        transformacion = [[0] * 2 for i in range(2)]
        transformacion[0][0]=1
        transformacion[0][1]=a
        transformacion[1][0]=0
        transformacion[1][1]=1
        #print(transformacion)
    return transformacion
import numpy as np
import math as math
import plotly.graph_objects as go
import matplotlib.pyplot as plt
opcion = input('Digita al opcion que desea 1:Fuguras muestra 2:Ingreso de puntos')
if opcion=='2':
    n=int(input("ingrese el numero de puntos que ingresara"))
    n=n+1
    matriz = [[0] * n for i in range(2)]
    n=n-1
            #Ciclo para obtener las coordenadas
    for i in range(0, n):
            print("Ingresa x del punto "+str(i+1))
            #coordenada en x
            x=float(input())
            matriz[0][i]=x
            print("Ingresa y del punto "+str(i+1))
            #coordenada en y
            y=float(input())
            matriz[1][i]=y
    matriz[0][n]=matriz[0][0]
    matriz[1][n]=matriz[1][0]
    matriz=np.matrix(matriz)
    MyShape=np.matrix(matriz)
    print(MyShape)
    NewShape=MyShape
elif opcion=='1':
    print("Elija una figuras de las siguientes opciones:\n1:Cuadrado\n2:Corazon\n3:Estrella\n4:Triangulo")
    opcionfig=input()
    if(opcionfig=='1'):
        NewShape = [[0] * 5 for i in range(2)]
        NewShape[0][0]=-2
        NewShape[1][0]=-2
        NewShape[0][1]=2
        NewShape[1][1]=-2
        NewShape[0][2]=2
        NewShape[1][2]=2
        NewShape[0][3]=-2
        NewShape[1][3]=2
        NewShape[0][4]=-2
        NewShape[1][4]=-2
    if(opcionfig=='2'):
        NewShape = [[0] * 7 for i in range(2)]
        NewShape[0][0]=0
        NewShape[1][0]=1
        NewShape[0][1]=3
        NewShape[1][1]=3
        NewShape[0][2]=2
        NewShape[1][2]=4
        NewShape[0][3]=0
        NewShape[1][3]=3.6
        NewShape[0][4]=-2
        NewShape[1][4]=4
        NewShape[0][5]=-3
        NewShape[1][5]=3
        NewShape[0][6]=0
        NewShape[1][6]=1
    if(opcionfig=='3'):
        NewShape = [[0] * 10 for i in range(2)]
        NewShape[0][0]=-5
        NewShape[1][0]=-9
        NewShape[0][1]=0
        NewShape[1][1]=5
        NewShape[0][2]=-9
        NewShape[1][2]=-5
        NewShape[0][3]=3
        NewShape[1][3]=-2
        NewShape[0][4]=8
        NewShape[1][4]=2
        NewShape[0][5]=2
        NewShape[1][5]=2
        NewShape[0][6]=0
        NewShape[1][6]=9
        NewShape[0][7]=-2
        NewShape[1][7]=2
        NewShape[0][8]=-8
        NewShape[1][8]=2
        NewShape[0][9]=-3
        NewShape[1][9]=-2
        NewShape[0][10]=-5
        NewShape[1][10]=-9
    if(opcionfig=='4'):
        NewShape = [[0] * 4 for i in range(2)]
        NewShape[0][0]=1
        NewShape[1][0]=8
        NewShape[0][1]=2
        NewShape[1][1]=7
        NewShape[0][2]=6
        NewShape[1][2]=7
        NewShape[0][3]=1
        NewShape[1][3]=8
    MyShape=NewShape
    print(NewShape)
if(opcion=='2' or opcion=='1'):
    while (True):
        opcion2 = input('Digita al opcion que desea \n1:Expansion \n2:Reflexion\n3:Corte\n4:Rotacion\n5:salir\n')
        fig=go.Figure( 
        go.Scatter (
        x =np.array(MyShape[0,:])[0],
        y =np.array(MyShape[1,:])[0],
        name = "original", 
        mode = "lines"
            )
        )
        if opcion2=='1':
            print("Ingrese la constante c para escalar la figura")
            c=(float(input()))
            print("Ingrese el eje en el que desea escalar la figura")
            axis=input()
            NewShape=scale2(c,axis)*NewShape
        elif opcion2=='2':
            print("Ingrese el eje en el que desea reflejar la figura")
            axis=input()
            NewShape=reflexion(axis)*NewShape
        elif opcion2=='3':
            print("Ingrese la constante c para recortar la figura")
            c=(float(input()))
            print("Ingrese el eje en el que desea recortar la figura")
            axis=input()
            NewShape=corte(axis,c)*NewShape
        elif opcion2=='4':
            print("Ingrese el angulo que desea que gire la figura")
            c=(float(input()))
            print("Grado en raddiantes: ")
            print(np.deg2rad(c))
            NewShape=rotar(c)*NewShape
        elif opcion2=='5' :
            print("Hasta luego :)")
        fig.add_trace(       
            go.Scatter(
                x =np.array(NewShape[0,:])[0],
                y =np.array(NewShape[1,:])[0],
                name = "scale", 
                mode = "lines"
                )

        )

        fig.update_layout( 
        xaxis =dict(range=[-8,8]), 
        yaxis =dict(range=[-8,8]), 
        autosize=False, 
        width=400,
        height=400
        )
        fig.show()
        if opcion2=='5':
            break