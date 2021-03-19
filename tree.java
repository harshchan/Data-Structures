import java.util.Scanner;



public class tree {

    static Scanner sc=null;
    public static void main(String[] args)
    {
        sc=new Scanner(System.in);

        Node root=createTree();

        System.out.print("\npreorder traversal is  ");
        preOrder(root);
        System.out.print("\nInorder traversal is  ");
        inOrder(root);

        System.out.print("\nPostorder Traversal is  ");
        postOrder(root);

    }

    static Node createTree()
    {
        Node root =null;
        System.out.println("Enter data : ");
        int data=sc.nextInt();
        if(data==-1)
            return null;
        root=new Node(data);

        System.out.println("Enter Data for Left "+data);
        root.left=createTree();
        System.out.println("Enter data for Right "+data);
        root.right=createTree();

        return root;
    }

    static void inOrder(Node root)
    {
        if(root==null)return;
        inOrder(root.left);
        System.out.print(root.data+" ");
        inOrder(root.right);
    }

    static void preOrder(Node root)
    {
        if(root==null)return;
        System.out.print(root.data+" ");
        preOrder(root.left);
        preOrder(root.right);
    }

    static void postOrder(Node root)
    {
        if(root==null)return;
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data+" ");
    }
}
class Node
{
    Node left,right;
    int data;
    Node(int x)
    {
        left=null;
        right=null;
        data=x;
    }
}

