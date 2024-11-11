W,H,x,y,r= map(int, input().split())
if W>=x+r & r<=x & r<=y & H>=y+r:
 print ("Yes")
else:
 print ("No")