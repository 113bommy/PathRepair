#input

a,b=map(int,input().split())



#variables
nicesum=(b*(b-1)/2)*(a*(a+1)/2)*b+(b*(b-1)/2)*a


#main
print(int(nicesum%1000000007))