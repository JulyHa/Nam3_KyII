
CREATE DATABASE [OnlineShop]

USE [OnlineShop]
GO
/****** Object:  Table [dbo].[Categories]    Script Date: 7/11/2021 11:33:10 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Categories](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[NameVN] [nvarchar](50) NULL,
 CONSTRAINT [PK_dbo.Categories] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Customers]    Script Date: 7/11/2021 11:33:10 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Customers](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Fullname] [nvarchar](50) NOT NULL,
	[Email] [nvarchar](50) NOT NULL,
	[Password] [nvarchar](50) NOT NULL,
	[RePassword] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_dbo.Customers] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[NavItems]    Script Date: 7/11/2021 11:33:10 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[NavItems](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[NavName] [nvarchar](50) NOT NULL,
	[NavNameVN] [nvarchar](50) NULL,
 CONSTRAINT [PK_dbo.NavItems] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[OrderDetails]    Script Date: 7/11/2021 11:33:10 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[OrderDetails](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[OrderId] [int] NOT NULL,
	[ProductId] [nvarchar](10) NOT NULL,
	[UnitPrice] [float] NOT NULL,
	[Quantity] [int] NOT NULL,
 CONSTRAINT [PK_dbo.OrderDetails] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Orders]    Script Date: 7/11/2021 11:33:10 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Orders](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[CustomerId] [int] NOT NULL,
	[OrderDate] [datetime] NOT NULL,
	[Address] [nvarchar](max) NULL,
	[Amount] [float] NULL,
	[Description] [nvarchar](max) NULL,
 CONSTRAINT [PK_dbo.Orders] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Products]    Script Date: 7/11/2021 11:33:10 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Products](
	[Id] [nvarchar](10) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[UnitPrice] [float] NOT NULL,
	[Image] [nvarchar](max) NULL,
	[Available] [bit] NOT NULL,
	[CategoryId] [int] NOT NULL,
	[Description] [nvarchar](max) NULL,
 CONSTRAINT [PK_dbo.Products] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Categories] ON 

INSERT [dbo].[Categories] ([Id], [Name], [NameVN]) VALUES (1, N'Food', N'Thực phẩm')
INSERT [dbo].[Categories] ([Id], [Name], [NameVN]) VALUES (2, N'Drink', N'Đồ uống')
INSERT [dbo].[Categories] ([Id], [Name], [NameVN]) VALUES (3, N'Assessories', N'Đồ gia dụng')
SET IDENTITY_INSERT [dbo].[Categories] OFF
SET IDENTITY_INSERT [dbo].[Customers] ON 

INSERT [dbo].[Customers] ([Id], [Fullname], [Email], [Password], [RePassword]) VALUES (1, N'James Bond', N'kh1@gmail.com', N'123', N'123')
INSERT [dbo].[Customers] ([Id], [Fullname], [Email], [Password], [RePassword]) VALUES (2, N'Tony Jaa', N'tj@gmail.com', N'456', N'456')
INSERT [dbo].[Customers] ([Id], [Fullname], [Email], [Password], [RePassword]) VALUES (3, N'Bruce Lee', N'bl@gmail.com', N'321', N'321')
INSERT [dbo].[Customers] ([Id], [Fullname], [Email], [Password], [RePassword]) VALUES (4, N'Jackie Chan', N'jc@gmail.com', N'654', N'654')
INSERT [dbo].[Customers] ([Id], [Fullname], [Email], [Password], [RePassword]) VALUES (5, N'Nguyễn Văn An', N'a@gmail.com', N'111', N'111')
INSERT [dbo].[Customers] ([Id], [Fullname], [Email], [Password], [RePassword]) VALUES (6, N'Nguyễn Văn An', N'a@gmail.com', N'123456', N'123')
INSERT [dbo].[Customers] ([Id], [Fullname], [Email], [Password], [RePassword]) VALUES (7, N'Nguyễn Văn An', N'adfadf', N'123456', N'123')
SET IDENTITY_INSERT [dbo].[Customers] OFF
SET IDENTITY_INSERT [dbo].[NavItems] ON 

INSERT [dbo].[NavItems] ([Id], [NavName], [NavNameVN]) VALUES (1, N'Home', N'Trang chủ')
INSERT [dbo].[NavItems] ([Id], [NavName], [NavNameVN]) VALUES (2, N'Offers', N'Hàng hóa')
INSERT [dbo].[NavItems] ([Id], [NavName], [NavNameVN]) VALUES (4, N'Help', N'Trợ giúp')
INSERT [dbo].[NavItems] ([Id], [NavName], [NavNameVN]) VALUES (5, N'Contact', N'Liên hệ')
SET IDENTITY_INSERT [dbo].[NavItems] OFF
SET IDENTITY_INSERT [dbo].[OrderDetails] ON 

INSERT [dbo].[OrderDetails] ([Id], [OrderId], [ProductId], [UnitPrice], [Quantity]) VALUES (1, 1, N'F01', 1000, 1)
INSERT [dbo].[OrderDetails] ([Id], [OrderId], [ProductId], [UnitPrice], [Quantity]) VALUES (2, 1, N'F04', 1000, 1)
INSERT [dbo].[OrderDetails] ([Id], [OrderId], [ProductId], [UnitPrice], [Quantity]) VALUES (3, 2, N'F01', 1000, 1)
INSERT [dbo].[OrderDetails] ([Id], [OrderId], [ProductId], [UnitPrice], [Quantity]) VALUES (4, 2, N'F03', 500, 1)
SET IDENTITY_INSERT [dbo].[OrderDetails] OFF
SET IDENTITY_INSERT [dbo].[Orders] ON 

INSERT [dbo].[Orders] ([Id], [CustomerId], [OrderDate], [Address], [Amount], [Description]) VALUES (1, 1, CAST(N'2019-03-30T00:00:00.000' AS DateTime), N'London', 1000, NULL)
INSERT [dbo].[Orders] ([Id], [CustomerId], [OrderDate], [Address], [Amount], [Description]) VALUES (2, 2, CAST(N'2019-03-30T00:00:00.000' AS DateTime), N'Paris', 1500, NULL)
SET IDENTITY_INSERT [dbo].[Orders] OFF
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'A01', N'Nồi lẩu', 500, N'hh1.png', 0, 3, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'A02', N'Bộ nồi', 400, N'hh2.png', 1, 3, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'A03', N'Khuôn bánh', 1200, N'hh3.png', 1, 3, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'A04', N'Bình nước', 500, N'hh4.png', 0, 3, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'A05', N'Nồi inox', 400, N'hh5.png', 1, 3, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'D01', N'Nước táo', 1200, N'bv1.png', 1, 2, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'D02', N'Nước cam', 500, N'bv2.png', 0, 2, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'D03', N'Nước dâu', 400, N'bv3.png', 1, 2, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'D04', N'Bia đen', 1000, N'bv4.png', 1, 2, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'D05', N'Coca', 1200, N'bv5.png', 1, 2, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'F01', N'Muối', 1000, N'1.png', 1, 1, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'F02', N'Hướng dương', 1200, N'2.png', 1, 1, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'F03', N'Bột mì', 500, N'3.png', 0, 1, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'F04', N'Súp TATA', 400, N'4.png', 1, 1, NULL)
INSERT [dbo].[Products] ([Id], [Name], [UnitPrice], [Image], [Available], [CategoryId], [Description]) VALUES (N'F05', N'Gạo', 1000, N'5.png', 1, 1, NULL)
ALTER TABLE [dbo].[OrderDetails]  WITH CHECK ADD  CONSTRAINT [FK_dbo.OrderDetails_dbo.Orders_OrderId] FOREIGN KEY([OrderId])
REFERENCES [dbo].[Orders] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[OrderDetails] CHECK CONSTRAINT [FK_dbo.OrderDetails_dbo.Orders_OrderId]
GO
ALTER TABLE [dbo].[OrderDetails]  WITH CHECK ADD  CONSTRAINT [FK_dbo.OrderDetails_dbo.Products_ProductId] FOREIGN KEY([ProductId])
REFERENCES [dbo].[Products] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[OrderDetails] CHECK CONSTRAINT [FK_dbo.OrderDetails_dbo.Products_ProductId]
GO
ALTER TABLE [dbo].[Orders]  WITH CHECK ADD  CONSTRAINT [FK_dbo.Orders_dbo.Customers_CustomerId] FOREIGN KEY([CustomerId])
REFERENCES [dbo].[Customers] ([Id])
GO
ALTER TABLE [dbo].[Orders] CHECK CONSTRAINT [FK_dbo.Orders_dbo.Customers_CustomerId]
GO
ALTER TABLE [dbo].[Products]  WITH CHECK ADD  CONSTRAINT [FK_dbo.Products_dbo.Categories_CategoryId] FOREIGN KEY([CategoryId])
REFERENCES [dbo].[Categories] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Products] CHECK CONSTRAINT [FK_dbo.Products_dbo.Categories_CategoryId]
GO
USE [master]
GO
ALTER DATABASE [OnlineShop] SET  READ_WRITE 
GO
