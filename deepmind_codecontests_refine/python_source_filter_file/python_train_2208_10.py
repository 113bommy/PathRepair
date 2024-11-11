t = int(input())

for ti in range(t):
    indices = []
    s = input()
    i = 0
    while(i < len(s)):
        if s[i] == 'o' and s[i:i+3] == 'one':
            indices += [ i + 1]
            i += 3
            continue
        elif s[i] == 't':
            if s[i:i+6] == 'twone':
                indices += [ i + 2]
                i += 6
            elif s[i:i+3] == 'two':
                indices +=[ i + 1]
                i += 3
            else:
                i += 1
            continue
            
        i += 1
    
    print(len(indices))
    for i in indices:
        print(i + 1 , end= ' ')
    print()

