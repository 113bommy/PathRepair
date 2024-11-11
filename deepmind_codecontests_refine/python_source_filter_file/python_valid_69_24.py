# Global array of powers of two
NUM_POWERS = 50
Powers = []

# Find n for the provided number and power of two
def FindN(x, p):
    ps = Powers[p]
    psl = len(ps)

    xs = str(x)
    xsl = len(xs)
    
    xn = "" # We'll build up the match in this string
    xnl = 0 # Length of xn
    pi = 0 # index into ps
    xi = 0 # index into xs
    n = 0 # number ops to make xs match ps

    while xi < xsl and pi < psl:
        if xs[xi] == ps[pi]:
            xn = xn + xs[xi]
            xnl += 1
            xi += 1
            pi += 1
        else:
            xi += 1
            n += 1
    
    # If we have reached the end of both strings there is nothing more to do
    if xi == xsl and pi == psl:
        n += psl - xnl

    # Else if we have reached the end of ps we need to delete the remaining
    # digits from x
    elif pi == psl:
        n += xsl - xi
    
    # Else we have reached the end of xs so we need to add the remaining digits
    # from ps
    else:
        n += psl - xnl

    return n

# Initialise the powers of two
p = 1
for i in range(0, NUM_POWERS):
    Powers.append(str(p))
    p *= 2

# Read the number of trials
num_trials = int(input())

# Test each number
for i in range(0, num_trials):
    x = int(input())
    min_n = 100000000
    for j in range(0, NUM_POWERS):
        n = FindN(x, j)
        if n < min_n:
            min_n = n

    print(min_n)