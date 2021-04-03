from django.urls import path
from . import views


app_name = 'Navigation'
urlpatterns = [
	#SiteUrl's
	path('',views.index,name = 'index'),
	
]