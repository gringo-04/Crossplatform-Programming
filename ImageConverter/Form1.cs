using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            var OFD = new System.Windows.Forms.OpenFileDialog();
            if (OFD.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {

                var original = new Bitmap(Bitmap.FromFile(OFD.FileName)); 
                pictureBox1.Image = Image.FromFile(OFD.FileName); 
                var newImage = new Bitmap(Bitmap.FromFile(OFD.FileName)); 
                for (int row = 0; row < original.Width; row++) 
                {
                    for (int column = 0; column < original.Height; column++) 
                    {
                        var pixel = original.GetPixel(row, column); 
                        var avg = ((int)pixel.R + (int)pixel.B + (int)pixel.G) / 3; 
                        newImage.SetPixel(row, column, Color.FromArgb(avg, avg, avg)); 
                    }
                }

                newImage.Save("C:\\Users\\Bahhtee\\Desktop\\BandW\\Black_And_White.jpg");
                pictureBox2.Image = Image.FromFile("C:\\Users\\Bahhtee\\Desktop\\BandW\\Black_And_White.jpg");
            }
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
