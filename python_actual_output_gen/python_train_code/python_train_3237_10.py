x,y=map(int,input().split())
liste=list(map(int,input().split()))
z=0
 
for loop in range(x):
    if liste[loop]>liste[y-1] and liste[y-1] >0:
        z+=1
 
print(z)