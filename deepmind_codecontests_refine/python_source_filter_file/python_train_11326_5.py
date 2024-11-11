h,w,a,b=map(int,input().split())
l=[[0 if i<a else 1 for i in range(w)]if j<b else [0 if i>=a else 1 for i in range(w)]for j in range(h) ]
for i in l:
    print(" ".join(map(str,i)))