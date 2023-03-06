using System;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.TreeView;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {
        String name = String.Empty; 
        string gender = String.Empty;
        string[] facilities;
        string course = String.Empty;
        string DOB;
        Boolean valid;
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            name = textBox1.Text;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                gender = radioButton1.Text;
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked)
            {
                gender = radioButton2.Text;
            }
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton3.Checked)
            {
                gender = radioButton3.Text;
            }
        }

        private void label2_Click_1(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            course = comboBox1.Items[comboBox1.SelectedIndex].ToString();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            validate_inputs();
            String text = "Name: " + name +
                 "\nDOB: " + DOB.ToString() +
                  "\nGender: " + gender +
                   "\n Course: " + course;
            string message = "Confirm ?";
            string title = "Student Registraition Form";
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;
            DialogResult result = MessageBox.Show(message, title, buttons);
            if (result == DialogResult.Yes)
            {
                MessageBox.Show(text, "Form Submitted", MessageBoxButtons.OK);

            }
            else
            {
                // Do something  
            }  
        }

        private void monthCalendar1_DateChanged(object sender, DateRangeEventArgs e)
        {
            DOB = monthCalendar1.SelectionRange.Start.ToShortDateString();;
        }
        private void validate_inputs()
        {
            valid = true;
            if (string.IsNullOrEmpty(name))
            {
                DialogResult res = MessageBox.Show("Name cannot be empty!", "Warning", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
                valid = false;
            }
        }
    }
}
