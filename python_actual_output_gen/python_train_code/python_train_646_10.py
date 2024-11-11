n = int(input().strip())

s = input().strip()

max_set = 0

for x in range(n):
    for y in range(x,n):
        char_dict = {}
        if all(c.islower() for c in s[x:y]):
            for z in s[x:y]:
                if z in char_dict:
                    char_dict[z] += 1
                else:
                    char_dict[z] = 1
            
            if max_set < len(char_dict):
                max_set = len(char_dict)
print(max_set)