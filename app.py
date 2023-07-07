from flask import Flask, render_template, request
import serial

# set up serial
ser = serial.Serial('COM3', 9600)

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('frontPage.html')  # updated line

@app.route('/lift_rocket', methods=['POST'])
def lift_rocket():
    ser.write(b'1')
    return 'OK'

@app.route('/lower_rocket', methods=['POST'])
def lower_rocket():
    ser.write(b'2')
    return 'OK'

if __name__ == '__main__':
    app.run(debug=True)
