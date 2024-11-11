class complete_btree:
    def __init__(self, vals):
        self.vals=vals
        self.index_max = len(self.vals)

    def check(self, i):
        assert(i >= 1)
        assert(i <= self.index_max)

    def val_at(self, i):
        self.check(i)
        return self.vals[i-1]

    def left_idx(self, i):
        self.check(i)
        t = 2*i
        if t <= self.index_max:
            return t
        else:
            return None

    def right_idx(self, i):
        self.check(i)
        t = 2*i + 1
        if t <= self.index_max:
            return t
        else:
            return None

    def parent_idx(self, i):
        self.check(i)
        t = i//2
        if t > 0:
            return t
        else:
            return None


if __name__ == "__main__":
    H = int(input())   # <= 250
    vals_str = input()   # |val|<=2,000,000,000 = 2e9
    vals = vals_str.split(' ')

    cbt = complete_btree(vals)
    for i in range(1, H+1):
        print('node {i}: key = {k},'.format(i=i, k=cbt.val_at(i)), end='')
        p_idx = cbt.parent_idx(i)
        l_idx = cbt.left_idx(i)
        r_idx = cbt.right_idx(i)
        if p_idx is not None:
            print('parent key = {k}, '.format(k=cbt.val_at(p_idx)), end='')
        if l_idx is not None:
            print('left key = {k}, '.format(k=cbt.val_at(l_idx)), end='')
        if r_idx is not None:
            print('right key = {k}, '.format(k=cbt.val_at(r_idx)), end='')
        print()