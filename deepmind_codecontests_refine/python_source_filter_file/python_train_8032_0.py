a=[input()for _ in[0]*int(input().split()[0])]
def f(a):
 try:(x,y,z,_),u={(x.index('*'),x[::-1].index('*'),x.count('*'),-len(x)):0for x in a if'*'in x}
 except:z=2
 return z>1or x<=u[0]or y<=u[1]or sum(u)
print('YNEOS'[f(a)|f(zip(*a))::2])