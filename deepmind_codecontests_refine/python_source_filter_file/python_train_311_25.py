while True:
    a,b=map(int,input().split())
    if a==0 and b==0:break
    for i in range(H):
    	for j in range(W):
    		if (i + j)%2 == 0:print('#',end="")
    		else:print(".",end="")
    	print("")
    print("")
