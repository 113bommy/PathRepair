n, b, d = input().split()
t = list(map(int, input().split()))
somme = 0
if sum(t) > int(d):
    s = 0
    for i in t:
        if i <= int(b) :
            s = s + i
            if s > int(d):
                s = 0
                somme = somme + 1

print(f"{somme}")