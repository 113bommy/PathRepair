import sys
input = sys.stdin.readline
for _ in range(int(input())):
    l,r,m=[int(x) for x in input().split()]
    for i in range(l,r+1):
        temp1,temp2=m//i,(m+i-1)//i
        #print(temp1,temp2,m-temp1*i,)
        if temp1!=0 and m-temp1*i<(r-l+1):
            print(i,l+m-temp1*i,l)
            break
        if temp2!=0 and temp2*i-m<(r-l+1):
            print(i,l,l+temp2*i-m)
            break