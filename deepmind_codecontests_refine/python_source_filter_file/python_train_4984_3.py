from itertools import product
n = int(input())
for _ in range(n):
    s = input()
    for alpha,beta in product([3,5,7,9,11,15,17,19,21,23,25],range(26)):
        g = "".join(chr((alpha*(ord(e)-ord("a"))+beta)%26+ord("a")) if not e == " " else " "  for e in s)
        if "that" in g or "this" in g: print(g); break
