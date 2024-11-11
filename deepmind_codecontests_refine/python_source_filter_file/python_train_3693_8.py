def make_palindrome(s):
    if len(s) == 0:
        return 'a'
    if len(s) == 1:
        return s+s
    i,j = 0,len(s)-1
    s = list(s)
    new_wrd = None
    while i < j:
        if s[i] != s[j]:
            new_wrd = True
            break
        i += 1
        j -= 1
    if new_wrd is not None:
        new_wrd = s[:j+1]+[s[i]]+s[j+1:]
        print(new_wrd)
        if  ''.join(new_wrd) == ''.join(new_wrd)[::-1]:
            return ''.join(new_wrd)
        else:
            new_wrd = s[:i]+[s[j]]+s[i:]
            print(new_wrd)
            if  ''.join(new_wrd) == ''.join(new_wrd)[::-1]:
                return ''.join(new_wrd)
            return 'NA'
    else:
        if i == j:
            new_wrd = s[:i+1]+[s[j]]+s[j:]
        else:
            new_wrd = s[:j+1]+['a']+s[i:]
        return ''.join(new_wrd)
    
if __name__ =='__main__':
    s = input()
    print(make_palindrome(s))