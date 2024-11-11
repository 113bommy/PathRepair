'''
def userName(s):
    for i in range(s.index('@')):
        if not '0' <= s[i] <= '9' or 'a' <= s[i] <= 'z' or 'A' <= s[i] <= 'Z':
            return False
        else:
            return True


def hostName(s):
    if '/' in s:
        for i in range(s.index('@') + 1, s.index('/')):
            if not '0' <= s[i] <= '9' or 'a' <= s[i] <= 'z' or 'A' <= s[i] <= 'Z' or s[i] == '.':
                return False
            else:
                return True
    else:
        for i in range(s.index('@', )):
            if not '0' <= s[i] <= '9' or 'a' <= s[i] <= 'z' or 'A' <= s[i] <= 'Z' or s[i] == '.':
                return False
            else:
                return True


def resourse(s):
    for i in range(s.index('/'), s.rindex('/')):
        if not '0' <= s[i] <= '9' or 'a' <= s[i] <= 'z' or 'A' <= s[i] <= 'Z' or s[i] == '.':
            return False
        else:
            return True


s = input()
'''
'''
    0123456789.......
 s='something@ipsu.edu.tetu.ge/pageone'
 userName='something'
'''


def check(s):
    sLen = len(s)
    if sLen == 0 or sLen > 16:
        return False
    for i in range(sLen):
        if not ('A' <= s[i] <= 'Z' or
                'a' <= s[i] <= 'z' or
                '0' <= s[i] <= '9' or
                s[i] == '_'):
            return False
    return True


def checkHost(hostName):
    hostLen = len(hostName)
    if hostLen == 0 or hostLen > 16:
        return False
    for item in hostName.split('.'):
        if not check(item):
            return False

    return True


s = input()
isUser, isHost, isResource = False, False, False

if '@' in s:
    atIndex = s.index('@')
    userName = s[0:atIndex]
    isUser = check(userName)
    slashIndex = s.index('/') if '/' in s else -1
    hostName = s[atIndex + 1: slashIndex] if slashIndex != -1 else s[atIndex + 1:]
    isHost = checkHost(hostName)
    if slashIndex == -1:
        isResource = True
    else:
        resource = s[slashIndex + 1]
        isResource = check(resource)

print('YES' if isUser and isHost and isResource else 'NO')
