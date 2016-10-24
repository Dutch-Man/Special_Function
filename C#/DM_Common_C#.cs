using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Collections;//包含动态数组ArrayList
using System.Security.Cryptography;//包含MD5相关内容


//使用时需要添加命名空间
namespace DM_Common_Space
{
    class DM_Common
    {
        //IntPut：字符串s
        //Function：判断一个字符串是不是由数字组成
        public static bool isNum(string s)
        {
            for (int i = 0; i < s.Length; i++)
            {
                byte tmpByte = Convert.ToByte(s[i]);
                if ((tmpByte < 48) || (tmpByte > 57))
                {
                    return false;
                }
            }
            return true;
        }

        //Function：对整形数组快速排序快速排序，排序结果从小到大
        public static void QuickSort_Num(int[] arry, int left, int right)
        {
            //左边索引小于右边，则还未排序完成
            if (left < right)
            {
                //取中间的元素作为比较基准，小于他的往左边移，大于他的往右边移
                int middle = arry[(left + right) / 2];
                int i = left - 1;
                int j = right + 1;
                while (true)
                {
                    //移动下标，左边的往右移动，右边的向左移动
                    while (arry[++i] < middle && i < right) ;
                    while (arry[--j] > middle && j > 0) ;
                    if (i >= j)
                        break;
                    //交换位置
                    int number = arry[i];
                    arry[i] = arry[j];
                    arry[j] = number;

                }
                QuickSort_Num(arry, left, i - 1);
                QuickSort_Num(arry, j + 1, right);
            }
        }


        //Function：对ArrayList(放字符串)快速排序快速排序，排序结果从小到大
        public static void QuickSort_Str(ArrayList arry, int left, int right)
        {
            //string.Compare("a", "b");
            //左边索引小于右边，则还未排序完成 　　
            if (left < right)
            {
                //取中间的元素作为比较基准，小于他的往左边移，大于他的往右边移 　　
                //int middle = arry[(left + right) / 2];
                string middle = arry[(left + right) / 2].ToString();
                int i = left - 1;
                int j = right + 1;
                while (true)
                {
                    //移动下标，左边的往右移动，右边的向左移动
                    //while (arry[++i] < middle && i < right) ;

                    while ((string.Compare(arry[++i].ToString(), middle) < 0)&&(i<right));

                    //while (arry[--j] > middle && j > 0) ;

                    while ((string.Compare(arry[--j].ToString(), middle) > 0) && (j > 0)) ;


                    if (i >= j)
                        break;
                    //交换位置
                    //int number = arry[i];
                    string str_tmp = arry[i].ToString();
                    arry[i] = arry[j];
                    arry[j] = str_tmp;

                }
                QuickSort_Str(arry, left, i - 1);
                QuickSort_Str(arry, j + 1, right);
            }
        }

        //Function：获取字符串的MD5
        public static string GetMD5Hash(string input)
        {
            if (input == null)
            {
                return null;
            }

            MD5 md5Hash = MD5.Create();

            // 将输入字符串转换为字节数组并计算哈希数据  
            byte[] data = md5Hash.ComputeHash(Encoding.UTF8.GetBytes(input));

            // 创建一个 Stringbuilder 来收集字节并创建字符串  
            StringBuilder sBuilder = new StringBuilder();

            // 循环遍历哈希数据的每一个字节并格式化为十六进制字符串  
            for (int i = 0; i < data.Length; i++)
            {
                sBuilder.Append(data[i].ToString("x2"));
                //Console.WriteLine("{0}  {1}", i + 1, data[i]);
            }

            // 返回十六进制字符串  
            return sBuilder.ToString();
        }
    }
}
