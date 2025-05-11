class TreeNode:
    def __init__(self, key=None, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right
        self.height = 0  # Added height initialization

    def __repr__(self):
        return '%s <- %s -> %s' % (
            self.left and self.left.key,
            self.key,
            self.right and self.right.key
        )

def print_tree(root, level=0, prefix=""):
    if root is None:
        return

    space = "    "
    # Print right side first
    print_tree(root.right, level + 1, "┌── ")

    # Print current node
    if level == 0:
        print(root.key)
    else:
        print(space * (level - 1) + prefix + str(root.key))

    # Print left side
    print_tree(root.left, level + 1, "└── ")

def in_order(root):
    if not root:
        return
    in_order(root.left)
    print(root.key, end=", ")
    in_order(root.right)

def pre_order(root):
    if not root:
        return
    print(root.key, end=", ")
    pre_order(root.left)
    pre_order(root.right)

def post_order(root):
    if not root:
        return
    post_order(root.left)
    post_order(root.right)
    print(root.key, end=", ")

def insert(root, node):
    if root is None:
        return node
    if root.key < node.key:
        root.right = insert(root.right, node)
    else:
        root.left = insert(root.left, node)
    return root

def search(root, value):
    if root is None or root.key == value:
        return root
    if value < root.key:
        return search(root.left, value)
    return search(root.right, value)

def get_height(node):
    if not node:
        return -1
    return node.height

def update_node_height(root):
    if not root:
        return
    root.height = max(get_height(root.left), get_height(root.right)) + 1
    update_node_height(root.left)
    update_node_height(root.right)

def balance_factor(node):
    if not node:
        return 0
    return get_height(node.left) - get_height(node.right)

def rotate_right(root):
    new_root = root.left
    root.left = new_root.right
    new_root.right = root

    root.height = max(get_height(root.left), get_height(root.right)) + 1
    new_root.height = max(get_height(new_root.left), get_height(new_root.right)) + 1

    return new_root

def rotate_left(root):
    new_root = root.right
    root.right = new_root.left
    new_root.left = root

    root.height = max(get_height(root.left), get_height(root.right)) + 1
    new_root.height = max(get_height(new_root.left), get_height(new_root.right)) + 1

    return new_root

def insert_avl(root, node):
    # Standard BST insertion
    if not root:
        return node

    if node.key < root.key:
        root.left = insert_avl(root.left, node)
    else:
        root.right = insert_avl(root.right, node)

    # Update height
    root.height = max(get_height(root.left), get_height(root.right)) + 1

    # Calculate balance factor
    balance = balance_factor(root)

    # Rotation cases
    # Left-Left case
    if balance > 1 and node.key < root.left.key:
        return rotate_right(root)

    # Right-Right case
    if balance < -1 and node.key > root.right.key:
        return rotate_left(root)

    # Left-Right case
    if balance > 1 and node.key > root.left.key:
        root.left = rotate_left(root.left)
        return rotate_right(root)

    # Right-Left case
    if balance < -1 and node.key < root.right.key:
        root.right = rotate_right(root.right)
        return rotate_left(root)

    return root


# Example usage
root = None
values = [15, 10, 5]
for value in values:
    node = TreeNode(value)
    root = insert_avl(root, node)
    print(f"\nAfter inserting {value}:")
    print_tree(root)