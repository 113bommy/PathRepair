def soroban(s):
    z = list()
    for i in range(len(s)):
        if s[i] == '0':
            z.append("O-|-OOOO")
        if s[i] == '1':
            z.append("O-|O-OOO")
        if s[i] == '2':
            z.append("O-|OO-OO")
        if s[i] == '3':
            z.append("O-|OOO-O")
        if s[i] == '4':
            z.append("O-|OOOO-")
        if s[i] == '5':
            z.append("-O|-OOOO")
        if s[i] == '6':
            z.append("-O|O-OOO")
        if s[i] == '7':
            z.append("-O|OO-OO")
        if s[i] == '8':
            z.append("-O|OOO-O")
        if s[i] == '9':
            z.append("-O|OOOO-")
    return z


print(*soroban(input()), sep='\n')
