#python 3

n = int(input())
s = input()
v = []
v = s.split(" ")
for i in range(n):
	v[i] = int(v[i])
v.append(0)
rez = 0
w = []
for i in range(2, n + 1):
        if (v[i] <= v[i - 1]):
            w.append(v[i - 1])
            rez += 1

print(rez)
s = ""
for i in range(rez):
            s += str(w[i]) + " "
print(s)
