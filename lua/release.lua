function file_read(path_read)    --��ȡMP3
    local file=io.open(path_read,"rb")
    info={}
    temp={}
    temp=file:read("*a")
    file:seek("end",-128)
    info=file:read("*a")
    file:close()
    return info
end

function mp3_info()   --mp3��Ϣ
    Title=string.sub(info, 4, 33)
    Artist=string.sub(info, 34, 63)
    Album=string.sub(info, 64, 93)
    Year=string.sub(info, 94, 97)
    Comment=string.sub(info, 98, 126)
    io.write("Title:"..Title.."\n".."Artist:"..Artist.."\n".."Album:"..Album.."\n".."Year:"..Year.."\n".."Comment:"..Comment.."\n")
end

function modify(modified,new)  --�޸�id3��Ϣ
intercept(modified)
str_new=string.gsub(info,str,new)
end

function intercept(modified)    --��ȡ�ַ���
    if modified=="Title" then
        str=string.sub(info, 4, 33)
    elseif modified=="Artist" then
        str=string.sub(info, 34, 63)
    elseif modified=="Album" then
        str=string.sub(info, 64, 93)
    elseif modified=="Year" then
        str=string.sub(info, 94, 97)
    elseif modified=="Comment" then
        str=string.sub(info, 98, 126)
    else
        error("error")
    end
    return str
end

function file_write(path_write)  --д���ļ�
    local file=io.open(path_write,"wb")
    local temp2
    temp2=string.gsub(temp,info,str_new)
    file:write(temp2)
    file:close()
end

function test(path)    --����
   file_read(path)
   mp3_info()
   modify("Artist","11111111")
   file_write("d:\\1234.mp3")
end
test("d:\\123.mp3")