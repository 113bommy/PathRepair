n=int(input())
n_y=1
yr=1
while n>n_y:
    yr=yr+1
    n_y=n_y+yr
    n=n-n_y
    if n<0:
        yr-=1
print(yr)    
        
