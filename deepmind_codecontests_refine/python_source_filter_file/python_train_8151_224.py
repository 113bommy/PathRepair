n,k,l,c,d,p,nl,np = map(int, input().split())

# n people k bootle l ml c lime d slice p salt 
# nl ml toast 1 slice np salt

liquid = k*l
toast = liquid // n
lime = c*d
salt = p // np 

print(min(salt, lime, toast)//n)