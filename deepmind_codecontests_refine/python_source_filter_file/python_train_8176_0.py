def is_nice(strs):
    strs = list(strs)
    if len(strs) < 26:
        return -1
    satis = False
    for i in range(len(strs)-26+1):
        ret = strs[i:i+26]
        seen = [0]*26
        for c in ret:
            if c == '?':
                continue
            seen[ord(c)-ord('A')] += 1
        if seen.count(0) != ret.count('?'):
            break
        else:
            satis = True
            miss = ''
            for j in range(len(seen)):
                if seen[j] == 0:
                    miss += chr(j+ord('A'))
            idx = 0
            for c in range(len(ret)):
                if ret[c] == '?':
                    strs[i+c] = miss[idx]
                    idx += 1
        if satis:
            break
    if satis == False:
        return -1
    
    for i in range(len(strs)):
        if strs[i] == '?':
            strs[i] = 'A'
    return ''.join(strs)

s = input()
print(is_nice(s))


        
            
        