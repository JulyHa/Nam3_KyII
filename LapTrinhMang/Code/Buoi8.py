# # Soạn thảo email
# import email
# import smtplib
# import ssl
#
# if __name__ == '__main__':
#     # Dùng ssl
#     port = 465
#     password = "nguyenngu*01"
#     smtp_server = "smtp.gmail.com"
#     frommail = "ngunt.01.tektra@gmail.com"
#     tomail = "nguyenthingu3107@gmail.com"
#     messge = """\
#             Subject: Test email
#
#             This is a test email"""
#     # Tạo context ssl
#     context = ssl.create_default_context()
#     server = smtplib.SMTP_SSL(smtp_server, port, context=context)
#     # Login
#     server.login("ngunt.01.tektra@gmail.com", password)
#     # Sau khi login viết lệnh gửi mail
#     server.sendmail(frommail, tomail, messge)

# # Soạn thảo email
# import smtplib
# import ssl
# if __name__ == '__main__':
#     # Dùng ssl
#     port = 587
#     password = "nguyenngu*01"
#     smtp_server = "smtp.gmail.com"
#     frommail = "ngunt.01.tektra@gmail.com"
#     tomail = "nguyenthingu3107@gmail.com"
#     messge = "This is a test email"
#     # Tạo context ssl
#     context = ssl.create_default_context()
#     server = smtplib.SMTP(smtp_server, port)
#     server.ehlo()
#     server.starttls(context=context)
#     server.ehlo()
#     # Login
#     server.login(frommail, password)
#     # Sau khi login viết lệnh gửi mail
#     server.sendmail(frommail, tomail, messge)

# Gửi html
import smtplib
import ssl
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

if __name__ == '__main__':
    smtp_server = "smtp.gmail.com"
    port = 465
    from_addr = "ngunt.01.tektra@gmail.com"
    to_addr = "nguyenthingu3107@gmail.com"
    password = "nguyenngu*01"

    # Soạn nội dung thư
    # Header
    message = MIMEMultipart()
    message["Subject"] = "Test mail"
    message["From"] = from_addr
    message["To"] = to_addr

    # Body(Có thể gửi cả text hoặc html)
    # Tạo text và html
    body = """\
        Hello, this is a test email"""
    html = """\
        <html>
            <body>
                <p>My name is _Juu</p>
                <a href = "https://www.facebook.com">Click me</a>
            </body>
        </html>"""
    # Ghep text và html
    ms1 = MIMEText(body, "plain")
    ms2 = MIMEText(html, "html")
    # Attach vào message
    message.attach(ms1)
    message.attach(ms2)

    # Tạo kết nối và sender
    context = ssl.create_default_context()
    server = smtplib.SMTP_SSL(smtp_server, port, context=context)
    # Login
    server.login(from_addr, password)
    server.sendmail(from_addr, to_addr, message.as_string())