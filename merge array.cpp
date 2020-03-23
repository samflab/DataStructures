#include &lt;iostream&gt;
#include &lt;algorithm&gt;

using namespace std;

int main()
{
    int n,m,i,q;
    cout&lt;&lt;&quot;Number of elements in A array:&quot;;
    cin&gt;&gt;n;
    cout&lt;&lt;&quot;Number of elements in B array:&quot;;
    cin&gt;&gt;m;
    int k=n+m;
    int a[n], b[m], merge[k];
    cout&lt;&lt;&quot;Enter the elements into A array: &quot;;
    for(i=0; i&lt;n; i++)
    {
        cin&gt;&gt;a[i];
    }
    cout&lt;&lt;&quot;Enter the elements into B array &quot;;
    for(i=0; i&lt;m; i++)
    {
        cin&gt;&gt;b[i];
    }
//merge
    for(i=0; i&lt;n; i++)
    {

        merge[i]=a[i];
    }
    for(int j=5, i=0; j&lt;k, i&lt;m; j++, i++)
    {
        merge[j]=b[i];
    }
    cout&lt;&lt;&quot;Now the new array after merging is :\n&quot;;
    sort(merge, merge+k);
    for(i=0; i&lt;k; i++)
    {
        cout&lt;&lt;merge[i]&lt;&lt;&quot; &quot;;
    }
    return 0;
}
