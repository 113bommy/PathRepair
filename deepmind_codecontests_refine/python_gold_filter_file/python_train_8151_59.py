n, k, l, c, d, p, nl, np=map(int,input().split())
total_drink=k*l 
toasts_drink=(total_drink//nl)
toasts_lime=c*d 
toasts_salt=p//np 
print(min(toasts_drink,toasts_lime,toasts_salt)//n)