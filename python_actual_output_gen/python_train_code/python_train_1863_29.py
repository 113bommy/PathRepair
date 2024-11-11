S=input()
k=int(input())
if (k > len(S)):
    print ("imposible")
else:
    print (max(0,len(set(S))))
