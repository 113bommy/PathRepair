entrada = input()
p = [int(x) for x in entrada.split()]

n,m,k = p[0], p[1], p[2]

a = input()
a = [int(x) for x in a.split()]

a.sort()
sesion = k*a[-1] + a[-2]

ans = int(m/(k+1))*sesion + (m% (k+1))*k


print(ans)