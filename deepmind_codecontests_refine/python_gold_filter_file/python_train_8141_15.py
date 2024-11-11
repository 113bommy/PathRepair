def find(s, string):
    inds = []
    for i in range(len(s)):
        if i + len(string) > len(s): break
        if s[i:i+len(string)] == string: inds.append(i)
    return set(inds)

t = int(input())
for i in range(t):
    s = input()
    ones = find(s, "one")
    twos = find(s, "two")
    both = find(s, "twone")

    inds = []
    for item in ones:
        if item-2 not in both:
            inds.append(item+1)
    for item in twos:
        if item not in both:
            inds.append(item+1)
    for item in both:
        inds.append(item+2)
    print(len(inds))
    print(" ".join(str(x+1) for x in inds))
    
