
def f(n, d):    
    if d.count('A') > d.count('D'):
        return "Anton"
    elif d.count('A') < d.count('D'):
        return "Danik"
    else:
        return "Friendship"
if __name__ == '__main__':
    n = int(input())
    d = input()
    f(n, d)
