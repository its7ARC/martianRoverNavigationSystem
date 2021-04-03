from django.shortcuts import render

#PageRenderImport
from django.shortcuts import render,get_object_or_404
from django.http import HttpResponse,HttpResponseRedirect,Http404,JsonResponse
from django.urls import reverse
from django.utils import timezone


def index(request):
	return render(request, 'Navigation/index.html', {})