m = 0
c = 0
l = 0
xl = 0
xxl = 0
xxxl = 0
xs = 0
xxs = 0
xxxs = 0
o = 0
n = int(input())
for i in range (n):
    s = input()
    if s == 'M': m = m+1
    if s == 'S': c = c+1
    if s == 'L': l = l+1
    if s == 'XS': xs = xs+1
    if s == 'XXS': xxs = xxs+1
    if s == 'XXXS': xxxs = xxxs+1
    if s == 'XL': xl = xl+1
    if s == 'XXL': xxl = xxl+1
    if s == 'XXXL': xxxl = xxxl+1
for i in range (n):
    s = input()
    if s == 'M' and m > 0: m = m-1
    if s == 'S'and c > 0: c = c-1
    if s == 'L'and l > 0: l = l-1
    if s == 'XS'and xs > 0: xs = xs-1
    if s == 'XXS'and xxs > 0: xxs = xxs-1
    if s == 'XXXS'and xxxs > 0: xxxs = xxxs-1
    if s == 'XL'and xl > 0: xl = xl-1
    if s == 'XXL'and xxl > 0: xxl = xxl-1
    if s == 'XXXL'and xxxl > 0: xxxl = xxxl-1  
o = m +c+l+xl+xxl+xxxl+xs+xxs+xxxs
print (o)