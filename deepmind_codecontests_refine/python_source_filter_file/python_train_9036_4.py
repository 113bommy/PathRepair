s=input()
t=list(s).count("W")
A=[i for i,x in enumerate (list(s)) if x=="W"]
print(int(sum(A)-t*(t+1)/2))