def value(alp, string):
    s = 0
    for i,item in enumerate(string):
        s += (i + 1) * alp[item]
    return s

alphabet = ["a","b","c","d","e","f","g","h","i","j","k","l","m","o","p","q","r","s","t","u","v","w","x","y","z"]

s = input()
n = int(input())
values = list(map(int, input().split(" ")))

print(value(dict(zip(alphabet, values)), s + n*alphabet[values.index(max(values))]))


