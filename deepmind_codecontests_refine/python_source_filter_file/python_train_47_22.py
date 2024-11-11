
def cut_trees(trees):
    left_boundary = -1

    trees_cut = 0
    for i in range(len(trees)):
        cx, ch = trees[i]  # current tree
        if i == 0:
            # just cut first tree to the left
            left_boundary = cx
            trees_cut += 1
        elif i == len(trees) - 1:
            # cut it to the right
            trees_cut += 1
        else:
            nx, _ = trees[i + 1]  # next tree

            cut_left = cx - ch > left_boundary
            cut_right = cx + ch < nx

            if cut_left:
                left_boundary = cx
                trees_cut += 1
            elif cut_right:
                left_boundary = nx
                trees_cut += 1
            else:
                left_boundary = cx

    return trees_cut


def run_alg():
    num_trees = int(input())
    trees = []
    for _ in range(num_trees):
        line_data = input().split(' ')
        tree = int(line_data[0]), int(line_data[1])
        trees.append(tree)
    print(cut_trees(trees))


if __name__ == '__main__':
    run_alg()

