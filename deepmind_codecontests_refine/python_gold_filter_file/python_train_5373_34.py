S=input()
k=int(input())
if (k > len(S)):
    print ("impossible")
else:
    print (max(0,k-len(set(S))))
