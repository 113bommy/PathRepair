def main():
 n,a=map(int,open(0).read().split());d,s=[0]*n,0
 for i,x in enumerate(a):
  if i+x<n:d[i+x]+=1
  if i-x>=0:s+=d[i-x]
 print(s)
main()